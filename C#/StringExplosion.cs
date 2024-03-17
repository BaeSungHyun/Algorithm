using System.Text;


namespace baekjoon_9935
{

    public class Program
    {
        public static void Main()
        {
            using StreamWriter wr = new (new BufferedStream(Console.OpenStandardOutput()));

            StringBuilder before = new ();

            string str = Console.ReadLine();
            string bomb = Console.ReadLine();

            bool done;
            int index;

            // check last element for deletion 
            for (int i = 0; i < str.Length; i++)
            {
                before.Append(str[i]);

                if (before.Length >= bomb.Length && str[i] == bomb[^1]) // wHAT THE FUCK?!?!? LINQ - .Last() TAKES SO LONG
                {
                    done = true;
                    index = 0;

                    for (int j = before.Length - bomb.Length; j < before.Length; j++)
                    {
                        if (before[j] != bomb[index++])
                        {
                            done = false;
                            break;
                        }
                    }

                    if (done)
                    {
                        before.Remove(before.Length - bomb.Length, bomb.Length);
                    }
                }
            }

            wr.Write(before.Length == 0 ? "FRULA" : before);
        }
    }
}