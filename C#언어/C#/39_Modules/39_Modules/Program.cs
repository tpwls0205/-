﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace _8_Modules
{
    class Program
    {
        static void Main(string[] args)
        {
            Process p = Process.GetProcessById(724);
            ProcessModuleCollection col =
                p.Modules;
            foreach (ProcessModule M in col)
            {
                Console.WriteLine("\t이름={0}",
                    M.ModuleName);
            }
        }
    }
}
