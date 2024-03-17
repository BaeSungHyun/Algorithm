using System;

namespace GreedyMaxMeetings
{
    internal class GreedyMaxMeetings
    {
        public struct Meeting : IComparable<Meeting> // Specifying T inside 'IComparable<in T>' is much faster. 
        {
            public int start { get; set; }
            public int end { get; set; }
            public Meeting(int start, int end)
            {
                this.start = start;
                this.end = end;
            }

            public int CompareTo(Meeting obj)
            {
                Meeting m = obj;

                if (m.end == this.end)
                {
                    return this.start - m.start;
                }
                return this.end - m.end;
            }
        }
        public static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

            int numMeeting = int.Parse(sr.ReadLine());
            Meeting[] meetings = new Meeting[numMeeting];

            for (int i = 0; i < numMeeting; i++)
            {
                string[] str = sr.ReadLine().Split(' ');
                meetings[i] = new Meeting(int.Parse(str[0]), int.Parse(str[1]));
            }
            Array.Sort(meetings);


            int answer = 1;
            int index = 0;
            Meeting limitMeeting = meetings[index];

            while (index < numMeeting - 1)
            {
                while (index < numMeeting - 1 && meetings[++index].start < limitMeeting.end) ;

                if (meetings[index].start >= limitMeeting.end)
                {
                    limitMeeting = meetings[index];
                    answer++;
                }
            }

            //int prev = 0, answer = 0;
            //for (int i = 0; i < numMeeting; i++)
            //{
            //    if (meetings[i].start >= prev)
            //    {
            //        answer++;
            //        prev = meetings[i].end;
            //    }
            //}

            sw.WriteLine(answer);

            sw.Flush();
            sr.Close(); 
            sw.Close();
        }
    }
}
