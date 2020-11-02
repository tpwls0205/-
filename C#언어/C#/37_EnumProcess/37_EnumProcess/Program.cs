﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace _6_EnumProcess
{
    class Program
    {
        static void Main(string[] args)
        {
            Process[] Procs = 
                Process.GetProcesses(); // 작업관리자 속 프로세스 목록을 배열에 저장
            foreach (Process p in Procs)
            {
                Console.WriteLine("ID={0,5}, "
                    + "이름={1}",
                    p.Id, p.ProcessName);
            }
        }
    }
}
