using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csRotate : MonoBehaviour
{
    float speed = 20f;
    void Update()
    {
        transform.Rotate(Vector3.up * Time.deltaTime * speed);
        if (transform.rotation.eulerAngles.y >= 90f && transform.rotation.eulerAngles.y <= 270f)
        {
            speed = 120f;
        }
        else
            speed = 20f;
    }
}
