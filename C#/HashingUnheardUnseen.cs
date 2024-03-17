using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace HashingUnheardUnseen
{
    internal class HashingUnheardUnseen
    {
        const int MOD = 1 << 14;
        const int BIT = MOD - 1;
        const int R = 31;

        static private int HashFunc(string input)
        {
            long mul = 1, res = 0;
            foreach (char c in input)
            {
                res = (res + mul * c) & BIT;
                mul = (mul * R) & BIT;
            }

            return (int)res;
        }

        public class Node // Cannot use struct like C++.
        {
            internal string name;
            internal Node? next;

            public Node()
            {
                next = null;
            }
        }

        internal class HashMap
        {
            public Node[] map;

            public HashMap()
            {
                map = new Node[MOD];
                for (int i = 0; i < MOD; i++)
                {
                    map[i] = new Node();
                }
            }

            public void insert(string input)
            {
                int h = HashFunc(input);
                Node current = map[h];
                Node temp = new();

                temp.name = input;

                temp.next = current.next;
                current.next = temp;
            }

            public void contains(string input, ref ArrayList al)
            {
                int h = HashFunc(input);

                Node? current = map[h];
                current = current.next;

                while (current != null)
                {
                    if (current.name == input)
                    {
                        al.Add(current.name);
                    }
                    current = current.next;
                }
            }
        }

        static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
            string[] nm = sr.ReadLine().Split(' ');
            
            Int32 n = int.Parse(nm[0]);
            Int32 m = int.Parse(nm[1]);

            HashMap hm = new HashMap();

            int alIndex = 0;
            ArrayList al = new ArrayList();

            for (int i = 0; i < n; i++)
            {
                string temp = sr.ReadLine();
                hm.insert(temp);
            }

            for (int i = 0; i < m; i++)
            {
                string temp = sr.ReadLine();
                hm.contains(temp, ref al);
            }

            al.Sort();

            sw.WriteLine(al.Count);
            foreach (object temp in al)
            {
                sw.WriteLine(temp);
            }

            sw.Flush();
            sr.Close();
            sw.Close(); 
        }
    }
}
