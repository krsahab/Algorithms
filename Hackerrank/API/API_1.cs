using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;

namespace Hackerrank
{
    internal class Program
    {
        //public static void Main(string[] args)
        //{
        //    Console.WriteLine(getTotalGoals("Barcelona", 2011));
        //}
        public static int getTotalGoals(string team, int year)
        {
            int totalGoals = 0;
            totalGoals += GetGoalsforTeam(team, "team1", year);
            totalGoals += GetGoalsforTeam(team, "team2", year);
            return totalGoals;
        }

        public static int GetGoalsforTeam(string team, string teamSequence, int year)
        {
            int totalGoals = 0;
            var result = GetPageData(team, teamSequence, year).Result;
            totalGoals += result.data.Sum(x => teamSequence == "team1" ? x.team1goals : x.team2goals);
            var totalPage = result.total_pages;
            while (totalPage > 1)
            {
                result = GetPageData(team, teamSequence, year, totalPage--).Result;
                totalGoals += result.data.Sum(x => teamSequence == "team1" ? x.team1goals : x.team2goals);
            }
            return totalGoals;
        }
        public static async Task<PageData> GetPageData(string team, string teamSequence, int year, int page = 1)
        {
            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri(@"https://jsonmock.hackerrank.com/api/");
                var responseData = await client.GetAsync("football_matches?year=" + year + "&" + teamSequence + "=" + team + "&page=" + page);
                var Jsonresult = responseData.Content.ReadAsStringAsync().Result;
                var result = JsonConvert.DeserializeObject<PageData>(Jsonresult);
                return result;
            }
        }
    }

    internal class PageData
    {
        public int page { get; set; }
        public int per_page { get; set; }
        public int total { get; set; }
        public int total_pages { get; set; }
        public List<MatchData> data = new List<MatchData>();
    }

    internal class MatchData
    {
        public string competition { get; set; }
        public int year { get; set; }
        public string round { get; set; }
        public string team1 { get; set; }
        public string team2 { get; set; }
        public int team1goals { get; set; }
        public int team2goals { get; set; }
    }
}
