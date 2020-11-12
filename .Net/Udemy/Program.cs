using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Udemy
{
    class Program
    {
        static void Main(string[] args)
        {
            
            //Student newstudent = new Student() { rollNO = 121, name = "Aakash", college = "JECRC", st = new CSStudent() { subject = "DSA" } };
            //newstudent.getgrade();
            //newstudent.printtype<string>("Myname");
            //newstudent.st["Math"] = 30;
            //newstudent.st["DSA"] = 50;
            //Console.WriteLine(newstudent.name +" "+ newstudent.rollNO+" " +newstudent.college);
            //newstudent.st.getInterest();
            //Console.WriteLine(newstudent.st.subject);
            //Console.WriteLine(newstudent.st["Math"]);
            //Console.WriteLine(newstudent.st["DSA"]);
            //Console.WriteLine(newstudent.st.getavg(1,2,3,4,5,6,7,8));
            //string a = "1";
            //int a1;
            //if(int.TryParse(a,out a1))
            //{
            //    Console.WriteLine(a);
            //}
            //GenericClass<string> gc = new GenericClass<string>();
            //gc.Printtype("I am String");
            //Action<string> gcp = CSStudent.printstr;
            //gcp += CSStudent.printstr2;
            //gc.process("print this string", gcp);
            //Action sum = () => Console.WriteLine("");
            //Console.WriteLine(sum(2,4));

            //CSStudent cs = new CSStudent();
            //cs.publishString += mailservice.print;
            //cs.publishString += messageservice.print;
            //cs.publishString += faxservice.print;
            //cs.processcomplete("print output");
            //cs.printext("This is extension method");

            //IList<int> coll = new List<int>() {1,2,3,4,5,6,7,8,9 };
            //var res = coll.Where(x => x < 5).OrderBy(x => x).Select(x => x).ToArray();
            //var res2 = from num in coll
            //           where num >= 5
            //           orderby num descending
            //           select num;
            //var res3 = coll.Skip(2).Take(3);
            //Array.ForEach(res, x => Console.WriteLine(x));

            //DateTime? dt = null;
            //DateTime dt2 = dt ?? DateTime.Today;
            //dynamic d;
            //d = 1;
            //long l = d;
            //try
            //{
            //    int i = 0;
            //    if (i == 0)
            //        throw new customeException("Divide by zero");
            //    int t = 2 / i;
            //}
            //catch (customeException ex)
            //{
            //    Console.WriteLine(ex.Message);
            //    //throw;
            //}

            //int a = 1, b = 2;
            //waitfuncAsync();
            //Console.WriteLine($"number is {a} and {b}");

            var persons = new[] { new { name = "Ashok", Age = "32", Village = "abc" }, new { name = "Ashok", Age = "32", Village = "abc" }
            ,new { name = "Ashok", Age = "32", Village = "abc" },
            new { name = "Ashok", Age = "32", Village = "abc" },
            new { name = "Ashok", Age = "32", Village = "abc" }};

            var res = from p in persons
                      select new { Name = p.name, Age = p.Age };

            foreach( var r in res)
            {
                Console.WriteLine($"Name = {r.Name}, Age = {r.Age}");
            }
        }
        
        public async static Task waitfuncAsync()
        {
            string Path = @"C:\Users\KUMARSAHAB\Documents\newfile.txt";
            using (StreamWriter sw = new StreamWriter(Path, true))
            {
                await sw.WriteAsync("Hello World");
            }
        }
    }

    class customeException :Exception
    {
        public customeException(string message) : base(message) { }
    }

    class Student : Istudent
    {
        int _rollNumber;

        string _name;

        string _college;

        public CSStudent st { get; set; }
        public int rollNO { get => _rollNumber; set => _rollNumber = value; }
        public string name { get => _name; set => _name = value; }
        public string college { get => _college; set => _college = value; }
        int Istudent.rollNO { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }
        string Istudent.name { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }
        string Istudent.college { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public void getgrade()
        {
            Console.WriteLine("Grade for "+name+" is not found");
        }

        public void printtype<T>(T t)
        {
            Console.WriteLine("Type of input is {0}",t.GetType());
        }

        void Istudent.readchar()
        {
            throw new NotImplementedException();
        }
    }

    class mailservice
    {
        public static void print(object o, string e)
        {
            Console.WriteLine("Publicshing mailservice"+e);
        }
    }
    class messageservice
    {
        public static void print(object o, string e)
        {
            Console.WriteLine("Publicshing message {e}");
        }
    }
    class faxservice
    {
        public static void print(object o, string e)
        {
            Console.WriteLine("Publicshing fax" + e);
        }
    }
}
