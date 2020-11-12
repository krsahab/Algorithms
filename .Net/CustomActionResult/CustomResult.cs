using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;
using System.Web;
using System.Web.Http;

namespace WebAPIApp.Controllers
{
    public class CustomResult : IHttpActionResult
    {
        public int Id { get; set; }
        public HttpRequestMessage Message { get; set; }
        public CustomResult(int id,HttpRequestMessage  m)
        {
            Id = id;
            Message = m;
        }
        public Task<HttpResponseMessage> ExecuteAsync(CancellationToken cancellationToken)
        {
            var res = new HttpResponseMessage { Content = new   StringContent(Id.ToString()), RequestMessage =Message };
            return Task.FromResult(res);
        }
    }
}