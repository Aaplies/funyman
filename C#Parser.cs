using System;

namespace Duck
{
	public class Program
	{
		public static long Main(string s)
		{
            {
                Dictionary<string, long> suffixes = new Dictionary<string, long>()
                {
                    {"k", 1000 },
                    {"m", 1_000_000 },
                    {"b", 1_000_000_000 },
                    {"t", 1_000_000_000_000 },
                    {"qa", 1_000_000_000_000_000 },
                    {"qi", 1_000_000_000_000_000_000 }
                };
                if (s.Contains(","))
                {
                    s = (new Regex(",")).Replace(s, "");
                }
                if (new Regex(@"[a-zA-Z]").Match(s).Length != 0)
                {
                    Regex rg_d = new Regex(@"[a-zA-Z]");
                    Regex rg_l = new Regex(@"[^a-zA-Z]\.?");
                    string letter = rg_l.Replace(s, "");
                    double digit = double.Parse(rg_d.Replace(s, ""));
                    double result = digit * (suffixes[letter]);
                    return Convert.ToInt64(result);
                }
                else
                {
                    long result = long.Parse(s);
                    return Convert.ToInt64(result);
                }
            }
        }
	}
}

