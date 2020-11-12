using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Udemy
{
    static class extStudent
    {
        public static void printext(this CSStudent cs, string m)
        {
            Console.WriteLine(m);
        }
    }
    class CSStudent
    {

        private string _subject;

        public string subject
        { get { return _subject; }
            set { _subject = value; }
        }

        private Dictionary<string,int> _scores = new Dictionary<string, int>();

        internal virtual void getInterest()
        {
            Console.WriteLine("No Interest");
        }

        public int this[string sub]
        {
            get { return _scores[sub]; }
            set { _scores[sub] = value; }
        }

        public int getavg(params int[] m)
        {
            return m.Sum() / m.Length;
        }

        public static void printstr(string s)
        {
            Console.WriteLine(s);
        }

        public static void printstr2(string s)
        {
            Console.WriteLine(s);
        }

        //public delegate void publish(object o, EventArgs e);
        //public event publish p;

        public event EventHandler publish;
        public event EventHandler<string> publishString;
        public void processcomplete(string s)
        {
            publishString(this, s);
        }
    }
}
