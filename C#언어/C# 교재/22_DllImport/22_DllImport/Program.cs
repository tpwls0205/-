using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;   // C, C++ 함수를 직접 호출

namespace _22_DllImport     // 보안과 같은 일을 할때 -> pinvoke.net -> 함수원형을 찾아 선언하고 사용하면 된다
{
    class Program
    {
        #region 외부 DLL 정의문
        [DllImport("User32.dll")]
        public static extern int MessageBox(int hParent,
            string Message, string Caption, int Type);
        //int WINAPI MessageBox(HWND hWnd,
        //  LPCTSTR lpText, LPCTSTR lpCaption, UINT uType
        //);
        [DllImport("Kernel32.dll")]
         public static extern uint WinExec(string Path,
            uint nCmdShow);       
        //UINT WINAPI WinExec(LPCSTR lpCmdLine,
        //            UINT   uCmdShow);

        #endregion
        static void Main(string[] args)
        {
            //MessageBox(NULL, "", "", MB_OK);
            MessageBox(0, "메모장을 실행합니다.",
                "알림", 0); 
            //WinExec("notepad.exe", SW_SHOW);
            WinExec("notepad.exe", 1);
        }
    }
}
