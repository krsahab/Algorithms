using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CodeFirst.Models;
using Company.Models;

namespace CodeFirst.Controllers
{
    public class PhotoController : Controller
    {
        // GET: Photo
        CompanyDBContext db = new CompanyDBContext();
        public ActionResult Index()
        {
            return View(db.Photos.ToList());
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }

        public ActionResult AddPhoto()
        {
            return View();
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult AddPhoto(Photo ph, HttpPostedFileBase file)
        {
            if(ModelState.IsValid)
            {
                if(file != null)
                {
                    file.SaveAs(HttpContext.Server.MapPath("~/Content/Photos/")
                                                  + file.FileName);
                    ph.URL = file.FileName;
                }
                db.Photos.Add(ph);
                db.SaveChanges();
            }
            return RedirectToAction("Index","Photo");
        }
    }
}