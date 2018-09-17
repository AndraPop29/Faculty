using System;
using System.Net;
using System.Threading.Tasks;
using System.Linq;

namespace PPD_Lab5
{
    public sealed class Downloader
    {
        private readonly string _url;
        private readonly WebClient _client;

        public Downloader(string url)
        {
            _url = url;
            _client = new WebClient();
        }
        public async Task DoSingleJobAsync()
        {
            // Please see documentation on MSDN...
            await _client.DownloadFileTaskAsync(_url,
                Guid.NewGuid() +
                ".jpg"); // Most methods in the WebClient class have "async" overloads which are named appropriately.
        }

        public static async Task DoAllJobsAsync(params string[] urls)
        {
            // This method returns when all tasks have been completed.
            await Task.WhenAll(from url in urls
                               select new Downloader(url)
                                   .DoSingleJobAsync()); // This is a LINQ statement equivalent to iterating over all URLs with a foreach and calling "DoSingleJobAsync".
        }
    }

}
