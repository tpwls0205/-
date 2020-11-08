using Boomlagoon.JSON;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csWriteData : MonoBehaviour
{
    public InputField inputEmail;
    public InputField inputScore;
    public InputField inputX;
    public InputField inputY;
    public InputField inputZ;
    public Text textResult;

    public void writeData()
    {
        StartCoroutine(coWriteData());
    }

    IEnumerator coWriteData()
    {
        string url = "http://localhost:12000/13_writeRead.php";
        string email = inputEmail.text;
        string score = inputScore.text;
        string x = inputX.text;
        string y = inputY.text;
        string z = inputZ.text;

        WWWForm form = new WWWForm();
        form.AddField("iswrite", "1");
        form.AddField("email", email);
        form.AddField("score", score);
        form.AddField("x", x); 
        form.AddField("y", y);
        form.AddField("z", z);

        UnityWebRequest request = new UnityWebRequest();

        using(request = UnityWebRequest.Post(url, form))
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
                JSONObject json = JSONObject.Parse(request.downloadHandler.text);
                string result = json.GetString("result");
                switch (result)
                {
                    case "update":
                        textResult.text = "기존 데이터 변경";
                        break;
                    case "insert":
                        textResult.text = "새로 데이터 추가";
                        break;
                    default:
                        textResult.text = "error : " + json.GetString("error");
                        break;
                }
            }
        }
    }
}
