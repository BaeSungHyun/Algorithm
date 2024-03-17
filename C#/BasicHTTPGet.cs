using System;
using System.Net.Http;
using System.Threading.Tasks;

namespace BasicHTTPGet
{
    internal class BasicHTTPGet
    {
        static async Task Main()
        {
            using var client = new HttpClient();

            HttpResponseMessage response = await client.GetAsync("http://google.com");
            string responseBody = await response.Content.ReadAsStringAsync();
            Console.WriteLine($"Status: {(int)response.StatusCode}, Reason: {response.ReasonPhrase}");
            Console.WriteLine(responseBody);
        }
    }
}
