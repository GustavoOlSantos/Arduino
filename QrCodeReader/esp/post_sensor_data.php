<?php

$servername = "localhost";
// REPLACE with your Database name
$dbname = "espTest";
// REPLACE with Database user
$username = "root";
// REPLACE with Database user password
$password = "";

// Keep this API Key value to be compatible with the ESP32 code provided in the project page. 
// If you change this value, the ESP32 sketch needs to match
$api_key_value = "keykey";

$api_key = $location = $num_os = "";


//$info = phpinfo();
//echo $info;

if ($_SERVER["REQUEST_METHOD"] == "POST") {


    $api_key = test_input($_POST["api_key"]);

    if ($api_key == $api_key_value) {


        $location = test_input(intval($_POST["location"]));
        $num_os   = test_input($_POST["num_os"]);

        if ($location >= 7 && $location < 14) {


            echo "DataAlongSide : " . $location . "<br>";
            echo "QRData    : " . $num_os   . "<br>";

            echo "<script> alert('Escrita no banco de dados autorizada!')</script>";

            // Create connection
            $conn = new mysqli($servername, $username, $password, $dbname);
            // Check connection
            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }
            
            // Make your Own SQL QUERY
            //$sql = "INSERT INTO EspTable (location,num_os)VALUES ('$location', '$num_os')";

            echo "<script> alert('Novo registro realizado no Banco!')</script>";


        } elseif ($location < 7 || $location == 15) {

            echo "<script> alert('Escrita no banco n autorizada :(!')</script>";
        }
            
                
    } else {
        echo "API Key Incorreta." /*Wrong API Key provided.*/;

        echo "<meta http-equiv='refresh' >";
    }
} else {

    echo "Nenhuma informação enviada pelo HTTP POST."  /*No data posted with HTTP POST.*/;
    echo "<meta http-equiv='refresh' >";
}

function test_input($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    echo $data;
    return $data;
}