using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UserData : MonoBehaviour
{
    private static UserData instance = null;
    public string email;
    public int score;
    public float x;
    public float y;
    public float z;

    public static UserData Instance
    {
        get { return instance; }
    }
    public string getUserData()
    {
        return "email: " + email + "score: " + score + "x: " + x + "y: " + y + "z: " + z;
    }
    private void Start()
    {
        instance = this;
        DontDestroyOnLoad(this); // scene이 전환 되어도 계속 존재해라
    }
}
