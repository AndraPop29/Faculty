using System;
using System.Text;
using System.Net.Sockets;


namespace PPD_Lab5
{
    // State object for receiving data from remote device.  
    public class StateObject
    {
        // Client socket.  
        public Socket workSocket = null;
        // Size of receive buffer.  
        public const int BufferSize = 256;
        // Receive buffer.  
        public byte[] buffer = new byte[BufferSize];
        // Received data string.  
        public StringBuilder sb = new StringBuilder();
    }

    public static class Programe
    {
        static void Main(string[] args)
        {
            // Download files through HTTP
            string[] files =
            {
                "https://orig00.deviantart.net/02d9/f/2009/357/6/8/shortest_day_sunrise_by_ccplusplus.jpg",
                "https://orig00.deviantart.net/f135/f/2010/099/0/a/tranquility_by_ccplusplus.jpg",
                "https://orig00.deviantart.net/77ea/f/2010/188/0/e/stop__watch__wonder____by_ccplusplus.jpg"
            };

            // This is a trick to call an async method in the main method of a console application.
            //Downloader.DoAllJobsAsync(files).GetAwaiter().GetResult();
            //Console.WriteLine("DONE");

            //write a simple parser for the HTTP protocol
            //it should be able only to get the header lines and to understand the Content-lenght: header line
            //1. Directly implement the parser on the callbacks (event-driven);
            //TasksClient.StartClient("microsoft.com").GetAwaiter().GetResult();
            TasksClient tk = new TasksClient();
            tk.StartClient("microsoft.com").GetAwaiter().GetResult();

            Console.WriteLine("End");
            Console.ReadKey();

           
        }
    }
}
