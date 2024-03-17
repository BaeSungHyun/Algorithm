using System.Collections.Generic;
using System.Text;


namespace DualPriorityQueue
{
    internal class DualPriorityQueue
    {
        static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

            int num = int.Parse(sr.ReadLine());

            while (num > 0)
            {
                int operations = int.Parse(sr.ReadLine());

                SortedMultiSet<int> ints = new SortedMultiSet<int>();

                while (operations > 0)
                {
                    string[] str = sr.ReadLine().Split(' ');
                    switch (str[0])
                    {
                        case "I":
                            {
                                int input = int.Parse(str[1]);
                                ints.Add(input);
                                break;
                            }
                        case "D":
                            {
                                if (ints.Empty())
                                {
                                    operations--;
                                    continue;
                                }
                                int input = int.Parse(str[1]);

                                if (input == 1)
                                {
                                    ints.RemoveLast();
                                } else if (input == -1)
                                {
                                    ints.RemoveFirst();
                                }
                                break;
                            }
                    }
                    operations--;
                }

                if (ints.Empty())
                {
                    sw.WriteLine("EMPTY");
                } else
                {
                    sw.WriteLine(ints.PeekLast() + " " + ints.PeekFirst());
                } 

                num--;
            }
            sw.Flush();
            sr.Close();
            sw.Close();
        }
    }

    public class SortedMultiSet<T> : IEnumerable<T>
    {
        private SortedDictionary<T, int> _dict;
        public int minimum = int.MaxValue;
        public T minimumKey;
        public int maximum = int.MinValue;
        public T maximumKey;

        public SortedMultiSet() { 
            _dict = new SortedDictionary<T, int>();
        }

        public bool Empty()
        {
            return _dict.Count == 0;
        }

        public bool Contains(T item)
        {
            return _dict.ContainsKey(item);
        }

        public void Add(T item)
        {
            var temp = Convert.ToInt32(item);
            if (_dict.ContainsKey(item))
            {
                _dict[item]++;
            }
            else
            {
                if (minimum > temp)
                {
                    minimum = temp;
                    minimumKey = item;
                }
                if (maximum < temp)
                {
                    maximum = temp;
                    maximumKey = item;
                }
                _dict.Add(item, 1);
            }
        }

        public void Add(IEnumerable<T> items)
        {
            foreach (var item in items)
            {
                Add(item);
            }
        }

        //public void Remove(T item)
        //{
        //    if (!_dict.ContainsKey(item))
        //        throw new ArgumentException();
        //    if (--_dict[item] == 0)
        //    {
        //        _dict.Remove(item);
        //        maximum = _dict.PeekLast();
        //    }
        //}

        public void RemoveLast()
        {
            if (--_dict[maximumKey] == 0)
            {
                _dict.Remove(maximumKey);
                if (_dict.Count != 0) { 
                    maximumKey = _dict.Last().Key;
                    maximum = Convert.ToInt32(maximumKey);
                } else
                {
                    maximum = int.MinValue;
                    minimum = int.MaxValue;
                }
            }
        }

        public void RemoveFirst()
        {
            if (--_dict[minimumKey] == 0)
            {
                _dict.Remove(minimumKey);
                if (_dict.Count != 0) {
                    minimumKey = _dict.First().Key;
                    minimum = Convert.ToInt32(minimumKey);
                } else
                {
                    minimum = int.MaxValue;
                    maximum = int.MinValue;
                }
            }
        }

        // Return the last value in the multiset
        public int PeekLast()
        {
            //if (!_dict.Any())
            //    throw new NullReferenceException();
            //return _dict.Last().Key;
            _dict.Remove(maximumKey);
            return maximum;
        }

        public T PeekFirst()
        {
            if (!_dict.Any()) 
                throw new NullReferenceException() ;
            return _dict.First().Key;
        }

        // Return the last value in the multiset and remove it
        //public T PopFirst()
        //{
        //    T item = PeekFirst();
        //    Remove(item);
        //    return item;
        //}
        //public T PopLast()
        //{
        //    T item = PeekLast();
        //    Remove(item);
        //    return item;
        //}
        public IEnumerator<T> GetEnumerator()
        {
            foreach (var kvp in _dict)
            {
                for (int i = 0; i < kvp.Value; i++)
                {
                    yield return kvp.Key;
                }
            }
        }

        //IEnumerator<T> IEnumerable<T>.GetEnumerator()
        //{
        //    return this.GetEnumerator();
        //}

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
