<?php
    $iswrite = $_REQUEST["iswrite"]; // write : 1, read : 0
    $email = $_REQUEST["email"];
    $score = $_REQUEST["score"];
    $x = $_REQUEST["x"];
    $y = $_REQUEST["y"];
    $z = $_REQUEST["z"];

    $data = array();
    $data["error"] = 0; // 아무 문제가 없다

    $ini_config = parse_ini_file("Config.ini");
    $db = new mysqli($ini_config["hostname"],
                     $ini_config["account"],
                     $ini_config["password"],
                     $ini_config["database"]);

    if(mysqli_connect_error()){
        $data["error"] = 1; // 에러가 발생했다
    }else if($iswrite == "1"){
        $query = sprintf("SELECT * FROM userInfo WHERE email='%s'"
                        , $email);
        $res = $db->query($query);
        if($res->num_rows > 0){
            $query = sprintf("UPDATE userInfo SET score='%s',x='%s',".
                            "y='%s',z='%s' WHERE email='%s'",
                            $score, $x, $y, $z, $email);
            $db->query($query);
            $data["result"] = "update";
        }else{
            $query = sprintf("INSERT INTO userInfo(email,score,x,y,z) ".
                            "VALUES('%s','%s','%s','%s','%s')",
                            $email, $score, $x, $y, $z);
            $db->query($query);
            $data["result"] = "insert";
        }
    }else if($iswrite == "0"){
        $query = sprintf("SELECT * FROM userInfo WHERE email ='%s'", $email);
        $res = $db -> query($query);
        if($res->num_rows > 0){
            $row = $res->fetch_assoc();
            $data["email"] = $row["email"];
            $data["score"] = (int)$row["score"];
            $data["x"] = (float)$row["x"];
            $data["y"] = (float)$row["y"];
            $data["z"] = (float)$row["z"];
            $data["result"] = "read";
        }else{
            $data["result"] = "noread";
        }
    }


    $db->close();

    echo json_encode($data);
?>