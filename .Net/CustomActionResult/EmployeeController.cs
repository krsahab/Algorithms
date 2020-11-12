using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using WebAPIApp.Models;
using WebAPIApp.DTO;
using AutoMapper;

namespace WebAPIApp.Controllers
{

    public class EmployeeController : ApiController
    {
        private AppDBContext db = new AppDBContext();

        public IEnumerable<EmployeeDTO> GetEmployees()
        {
            return db.Employees.ToList().Select(Mapper.Map<Employee,EmployeeDTO>);
        }

        public EmployeeDTO GetEmployee(int? Id)
        {
            if (Id != null)
            {
                var res = db.Employees.SingleOrDefault(e => e.Id == Id);
                if (res == null)
                    throw new HttpResponseException(HttpStatusCode.NotFound);
                return Mapper.Map<Employee, EmployeeDTO>(res);
            }
            throw new HttpResponseException(HttpStatusCode.BadRequest);
        }
        [HttpPost]
        public IHttpActionResult CreateEmployee(EmployeeDTO e)
        {
            if (ModelState.IsValid)
            {
                Employee temp = Mapper.Map<EmployeeDTO, Employee>(e);
                db.Employees.Add(temp);
                db.SaveChanges();
                e.Id = temp.Id;
                return Created<EmployeeDTO>(Request.RequestUri+"/"+e.Id,e);
            }
            else
            return BadRequest();
        }
        [HttpDelete]
        public HttpResponseMessage DeleteEmployee(int? Id)
        {
            if (Id != null)
            {
                var res = db.Employees.SingleOrDefault(e => e.Id == Id);
                if (res == null)
                    return Request.CreateResponse(HttpStatusCode.NotFound,Id);
                db.Employees.Remove(res);
                db.SaveChanges();
                return Request.CreateResponse(HttpStatusCode.OK);
            }
            return Request.CreateResponse(HttpStatusCode.BadRequest);
        }
        [HttpPut]
        public IHttpActionResult UpdateEmployee(int Id, EmployeeDTO e)
        {
            if(ModelState.IsValid)
            {
                var emp = db.Employees.SingleOrDefault(c => c.Id == Id);
                if (emp == null)
                    throw new HttpResponseException(HttpStatusCode.NotFound);
                Mapper.Map(e,emp);
                db.SaveChanges();
                return Ok(emp);
            }
            return BadRequest();
        }
    }
}
