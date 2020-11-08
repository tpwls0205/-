using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class csLoginInfo : MonoBehaviour
{
    public InputField inputEmail;
    public InputField inputPassword;
    public Text textResult;

    public void sendLoginInfo()
    {
        StartCoroutine(coLoginInfo());
    }

    IEnumerator coLoginInfo()
    {
        string url = "http://localhost:12000/12_loginInfo.php";
        string email = inputEmail.text;
        string password = inputPassword.text;

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
                Debug.Log(result);
                if (result == "2")
                    textResult.text = "등록되지 않은 사용자입니다";
                else if (result == "1")
                    textResult.text = "password가 틀렸습니다";
                else if (result == "0")
                {
                    textResult.text = "로그인 되었습니다";
                    StartCoroutine(coLoginView());
                }
                else if (result == "-1")
                    textResult.text = "서버에서 DB접속 오류입니다";
                else
                    textResult.text = "알 수 없는 응답입니다";
            }
        }
    }
    IEnumerator coLoginView()
    {
        yield return new WaitForSeconds(1.5f);
        SceneManager.LoadScene("02.LoginView");
    }
}
