using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class csClearData : MonoBehaviour
{
    public InputField inputEmail;
    public InputField inputScore;
    public InputField inputX;
    public InputField inputY;
    public InputField inputZ;

    public void clearData()
    {
        inputEmail.text = "";
        inputScore.text = "";
        inputX.text = "";
        inputY.text = "";
        inputZ.text = "";
    }
}
