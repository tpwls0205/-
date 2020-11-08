<?php
	// 서버주소/php파일/?a=100&b=50
	// request요청중에 인자를 통해서 값을 꺼내라
	$a = $_REQUEST["a"]; // a 인자 값을 꺼내라
	$b = $_REQUEST["b"]; // b 인자 값을 꺼내라
	// response 
	echo $a+$b;
?>