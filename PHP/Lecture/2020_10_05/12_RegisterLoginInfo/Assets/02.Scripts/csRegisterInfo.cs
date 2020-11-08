using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csRegisterInfo : MonoBehaviour
{
    public InputField inputEmail;
    public InputField inputPassword;
    public Text textResult;

    public void sendRegisterInfo()
    {
        StartCoroutine(coRegisterInfo());
    }

    IEnumerator coRegisterInfo()
    {
        string url = "http://localhost:12000/11_registerLoginInfo.php";
        string email = inputEmail.text;
        string password = inputPassword.text;

        // POST 방식으로 전송
        WWWForm form = new WWWForm();
        form.AddField("email", email);
        form.AddField("password", password);

        UnityWebRequest request = new UnityWebRequest();

        using (request = UnityWebRequest.Post(url, form))
        {
            yield return request.SendWebRequest();

            if (request.isNetworkError)
            {
                Debug.Log(request.error);
                textResult.text = request.error;
            }
            else
            {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                string result = request.downloadHandler.text;
                if(result == "1")
                {
                    textResult.text = "사용자가 등록되었습니다";
                }
                else if(result == "0")
                {
                    textResult.text = "이미 존재하는 사용자입니다";
                }
            }
        }
    }
}
