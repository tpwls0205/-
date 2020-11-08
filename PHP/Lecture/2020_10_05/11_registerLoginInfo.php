<?php
    $email = $_REQUEST["email"];
    $password = $_REQUEST["password"];
    $data = array();
    $data["error"] = 0;
    $result = 0;

    $ini_config = parse_ini_file("Config.ini");
    $db = new mysqli($ini_config["hostname"],
                    $ini_config["account"],
                    $ini_config["password"],
                    $ini_config["database"]);

    if(mysqli_connect_error()){
        $data["error"] = 1;
    }else{
        $query = sprintf("SELECT * FROM loginInfo WHERE email='%s'", $email);
        $res = $db->query($query);
        if($res->num_rows > 0){
            $result = 0;    // 이미 등록된 사용자
        }else{
            $query = sprintf("INSERT INTO loginInfo(email,password) VALUES('%s','%s')", 
                            $email, $password);
			$db->query($query);
			$result = 1;	// 새로 등록함
        }
		$res->close();
		$db->close();
    }
	echo $result;
?>