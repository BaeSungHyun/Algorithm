using System;
using System.Net;
using System.Text;
using System.Threading.Tasks;

class BasicHTTPServer
{
    public static async Task HandleIncomingConnections(HttpListener listener)
    {
        bool runServer = true;
        while (runServer)
        {
            var context = await listener.GetContextAsync();
            var response = context.Response;

            string responseString = "<html><body>Hello, world!</body></html>";
            byte[] buffer = Encoding.UTF8.GetBytes(responseString);

            response.ContentLength64 = buffer.Length;
            var responseOutput = response.OutputStream;

            await responseOutput.WriteAsync(buffer, 0, buffer.Length);
            responseOutput.Close();
        }
    }

    static async Task Main(string[] args)
    {
        HttpListener listener = new HttpListener();
        listener.Prefixes.Add("http://localhost:8000/");
        listener.Start();

        await HandleIncomingConnections(listener);
        listener.Close();
    }
}