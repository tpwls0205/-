<?php
    $email = $_REQUEST["email"];
    $password = $_REQUEST["password"];
    $data = array();
    $data["error"] = 0;
    $result = -1;

    $ini_config = parse_ini_file("Config.ini");
    $db = new mysqli($ini_config["hostname"],
                    $ini_config["account"],
                    $ini_config["password"],
                    $ini_config["database"]);
    if(mysqli_connect_error()){
        $data["error"] = 1;
        $result = -1;       // db 접속 오류       
    }else{
        $query = sprintf("SELECT * FROM loginInfo WHERE email='%s'", 
                        $email);
        $res = $db->query($query);
        if($res->num_rows > 0){
            $res->close();
            $query = sprintf("SELECT * FROM loginInfo WHERE email='%s' AND password='%s'",
                            $email, $password);
            $res = $db->query($query);
            if($res->num_rows > 0){
                $result = 0;    // id, password 모두 일치하는 사용자
            }else{
                $result = 1;    // id만 일치, password 불일치
            }
        }else{
            $result = 2;    // 사용자가 존재하지 않음
        }

        $res->close();
        $db->close();
    }

    echo $result;
?>