<?php
	// �����ּ�/php����/?a=100&b=50
	// request��û�߿� ���ڸ� ���ؼ� ���� ������
	$a = $_REQUEST["a"]; // a ���� ���� ������
	$b = $_REQUEST["b"]; // b ���� ���� ������
	// response 
	echo $a+$b;
?>