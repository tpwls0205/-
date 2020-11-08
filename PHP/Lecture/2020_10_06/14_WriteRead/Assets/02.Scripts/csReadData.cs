using Boomlagoon.JSON;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csReadData : MonoBehaviour
{
    public InputField inputEmail;
    public InputField inputScore;
    public InputField inputX;
    public InputField inputY;
    public InputField inputZ;
    public Text textResult;

    public void readData()
    {
        StartCoroutine(coReadData());
    }

    IEnumerator coReadData()
    {
        string url = "http://localhost:12000/13_writeRead.php";

        string email = inputEmail.text;

        WWWForm form = new WWWForm();
        form.AddField("iswrite", "0");
        form.AddField("email", email);

        UnityWebRequest request = new UnityWebRequest();

        using (request = UnityWebRequest.Post(url, form))
        {
            yield return request.SendWebRequest();
            if(request.isNetworkError)
            {
                Debug.Log(request.error);
                textResult.text = request.error;
            }
            else
            {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                JSONObject json = JSONObject.Parse(request.downloadHandler.text);
                string result = json.GetString("result");
                switch(result)
                {
                    case "read":
                        textResult.text = "데이터 읽어옴";
                        inputScore.text = json.GetNumber("score").ToString();
                        inputX.text = json.GetNumber("x").ToString();
                        inputY.text = json.GetNumber("y").ToString();
                        inputZ.text = json.GetNumber("z").ToString();

                        UserData.Instance.email = email;
                        UserData.Instance.score = (int)json.GetNumber("score");
                        UserData.Instance.x = (float)json.GetNumber("x");
                        UserData.Instance.y = (float)json.GetNumber("y");
                        UserData.Instance.z = (float)json.GetNumber("z");
                        break;
                    case "noread":
                        textResult.text = "데이터 존재하지 않음";
                        inputScore.text = "";
                        inputX.text = "";
                        inputY.text = "";
                        inputZ.text = "";
                        break;
                }
            }
            
        }
    }
}
