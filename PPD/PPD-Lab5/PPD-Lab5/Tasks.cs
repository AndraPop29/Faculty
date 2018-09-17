using System;
using System.Text;
using System.Net.Sockets;
using System.Threading.Tasks;
using System.Net;
using System.Threading;
using System.Linq;
using System.Text.RegularExpressions;

namespace PPD_Lab5
{
  
    public class TasksClient
    {
        // The port number for the remote device.  
        private const int port = 80;

        // The response from the remote device.  
        private static String response = String.Empty;

        // ManualResetEvent instances signal completion.  
        private static ManualResetEvent connectDone =
            new ManualResetEvent(false);
        private static ManualResetEvent sendDone =
            new ManualResetEvent(false);
        private static ManualResetEvent receiveDone =
            new ManualResetEvent(false);

        public async Task StartClient(String url)
        {
            // Connect to a remote device.  
            try
            {
                // Establish the remote endpoint for the socket.  
                // The name of the   
                // remote device is "host.contoso.com".  
                IPHostEntry ipHostInfo = Dns.GetHostEntry(url);
                IPAddress ipAddress = ipHostInfo.AddressList[0];
                IPEndPoint remoteEP = new IPEndPoint(ipAddress, port);

                // Create a TCP/IP socket.  
                Socket client = new Socket(ipAddress.AddressFamily,
                    SocketType.Stream, ProtocolType.Tcp);

                // Connect to the remote endpoint.  
                await Task.Run(() => client.BeginConnect(remoteEP,
                                                   new AsyncCallback(ConnectCallback), client));
                connectDone.WaitOne();
                // Send test data to the remote device.  
                string GETrequest = "GET / HTTP/1.1\r\nHost:" + ipAddress + "\r\nConnection: keep-alive\r\nAccept: text/html\r\nUser-Agent: CSharpTests\r\n\r\n";
                await Send(client, GETrequest);

                // Receive the response from the remote device.  
                await Receive(client);
                receiveDone.WaitOne();

                // Write the response to the console.  
                Console.WriteLine("Response received : {0}", response);

                // Release the socket.  


            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        private void ConnectCallback(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.  
                Socket client = (Socket)ar.AsyncState;

                // Complete the connection.  
                client.EndConnect(ar);
            
                Console.WriteLine("Socket connected to {0}",
                    client.RemoteEndPoint.ToString());
                connectDone.Set();

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        private async Task Receive(Socket client)
        {
            try
            {

                // Create the state object.  
                StateObject state = new StateObject();
                state.workSocket = client;
                await Task.Run(() => client.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                                                   new AsyncCallback(ReceiveCallback), state));

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        private void ReceiveCallback(IAsyncResult ar)
        {
           
            try
            {
                // Retrieve the state object and the client socket   
                // from the asynchronous state object.  
                StateObject state = (StateObject)ar.AsyncState;
                Socket client = state.workSocket;
               
                       
                // Read data from the remote device.  
                int bytesRead = client.EndReceive(ar);
                if (bytesRead > 0)
                {
                    state.sb.Append(Encoding.ASCII.GetString(state.buffer, 0, bytesRead));
                    if (state.sb.Length > 1)
                    {
                        response = state.sb.ToString();
                       
                        int contentLength = 0;
                        if (response.Contains("\r\n\r\n"))
                        {
                            // header is received, parsing content length
                            Regex reg = new Regex("\\\r\nContent-Length: (.*?)\\\r\n");
                            Match m = reg.Match(response);
                            contentLength = int.Parse(m.Groups[1].ToString());
                            // read the body
                            /*
                            bodyBuff = new byte[contentLength];
                            socket.Receive(bodyBuff, 0, contentLength, 0);
                            */
                        }
                        Console.WriteLine("--->Content length received from the site:" + contentLength);


                    }
                    receiveDone.Set();

                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        private async Task Send(Socket client, String data)
        {
            // Convert the string data to byte data using ASCII encoding.  
            byte[] byteData = Encoding.ASCII.GetBytes(data);

            await Task.Run(() => client.BeginSend(byteData, 0, byteData.Length, 0,
                                                  new AsyncCallback(SendCallback), client));
        }

        private static void SendCallback(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.  
                Socket client = (Socket)ar.AsyncState;

                // Complete sending the data to the remote device.  
                int bytesSent = client.EndSend(ar);
                Console.WriteLine("Sent {0} bytes to server.", bytesSent);

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

    }
}
