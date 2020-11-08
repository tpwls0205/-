using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;
using UnityEngine.Networking;

public class csRequest : MonoBehaviour
{
    private InputField inputA;
    private InputField inputB;
    private InputField inputResult;

    void Start()
    {
        inputA = GameObject.Find("InputA").GetComponent<InputField>();
        inputB = GameObject.Find("InputB").GetComponent<InputField>();
        inputResult = GameObject.Find("InputResult").GetComponent<InputField>();
    }

    public void RequestGet()
    {
        StartCoroutine(coGet());
    }

    IEnumerator coGet()
    {
        string url = "http:/localhost:12000/07_request_response.php?";
        string a = inputA.text;
        string b = inputB.text;
        url += string.Format("a={0}", a);
        url += "&";
        url += string.Format("b={0}", b);

        UnityWebRequest request = new UnityWebRequest();
        using (request = UnityWebRequest.Get(url))
        {
            yield return request.SendWebRequest();
            if (request.isNetworkError)
                Debug.Log(request.error);
            else
            {
                Debug.Log("<get>" + request.downloadHandler.text + "</get>");
                inputResult.text = request.downloadHandler.text;
            }
        }
    }

    public void RequestPost()
    {
        StartCoroutine(coPost());
    }

    IEnumerator coPost()
    {
        string url = "http://tpwls0205.dothome.co.kr/07_request_response.php";
        string a = inputA.text;
        string b = inputB.text;

        // post방식은 주소가 아닌 본문에 매개변수를 넣는다
        WWWForm form = new WWWForm();
        form.AddField("a", a);
        form.AddField("b", b);
        UnityWebRequest request = new UnityWebRequest();

        using (request = UnityWebRequest.Post(url, form))
        {
            yield return request.SendWebRequest();

            if (request.isNetworkError)
                Debug.Log(request.error);
            else
            {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                inputResult.text = request.downloadHandler.text;
            }
        }
    }
}
