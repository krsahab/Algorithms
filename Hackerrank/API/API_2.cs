using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;

namespace Hackerrank
{
    internal class Hackerrank2
    {
        public static void Main(string[] args)
        {
            string competition = "UEFA Champions League";
            int year = 2011;
            string winner = Winner(competition, year);
            Console.WriteLine(getTotalGoals(competition, year, winner));
        }
        public static int getTotalGoals(string competition, int year, string team)
        {
            int totalGoals = 0;
            totalGoals += GetGoalsforTeam(competition, year, "team1", team);
            totalGoals += GetGoalsforTeam(competition, year, "team2", team);
            return totalGoals;
        }

        public static string Winner(string name, int year)
        {
            var result = GetCompetetions(name, year).Result;
            return result.data[0].winner;
        }

        public static int GetGoalsforTeam(string competition, int year, string teamSequence, string team)
        {
            int totalGoals = 0;
            var result = GetCompetetionDetails(competition, year, teamSequence, team).Result;
            totalGoals += result.data.Sum(x => teamSequence == "team1" ? x.team1goals : x.team2goals);
            var totalPage = result.total_pages;
            while (totalPage > 1)
            {
                result = GetCompetetionDetails(competition, year, teamSequence, team, totalPage--).Result;
                totalGoals += result.data.Sum(x => teamSequence == "team1" ? x.team1goals : x.team2goals);
            }
            return totalGoals;
        }
        public static async Task<Page> GetCompetetions(string name, int year)
        {
            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri(@"https://jsonmock.hackerrank.com/api/");
                var responseData = await client.GetAsync("football_competitions?name=" + name + "&year=" + year);
                var Jsonresult = responseData.Content.ReadAsStringAsync().Result;
                var result = JsonConvert.DeserializeObject<Page>(Jsonresult);
                return result;
            }
        }
        public static async Task<PageData> GetCompetetionDetails(string competition, int year, string teamSequence, string team, int page = 1)
        {
            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri(@"https://jsonmock.hackerrank.com/api/");
                var responseData = await client.GetAsync("football_matches?competition=" + competition + "&year=" + year + "&" + teamSequence + "=" + team + "&page=" + page);
                var Jsonresult = responseData.Content.ReadAsStringAsync().Result;
                var result = JsonConvert.DeserializeObject<PageData>(Jsonresult);
                return result;
            }
        }
    }

    internal class Page
    {
        public int page { get; set; }
        public int per_page { get; set; }
        public int total { get; set; }
        public int total_pages { get; set; }
        public List<Match> data = new List<Match>();
    }

    internal class Match
    {
        public string name { get; set; }
        public int year { get; set; }
        public string country { get; set; }
        public string winner { get; set; }
        public string runnerup { get; set; }
    }
}
