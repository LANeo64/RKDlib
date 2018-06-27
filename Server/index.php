<?php

function resolveURI($url) {
    
}

if (isset($_GET["page"])) {
    $url = $_GET["page"];
    if ($url != "") {
        $urlArray = explode('/', $url);
        //var_dump($urlArray);
        if ($urlArray[0] == "lokStav") {
            if ($urlArray[1] != "") {
                $data = file_get_contents("./data/" . $urlArray[1]);
            } else {
                include_once "./default.php";
            }
        } elseif (strpos($urlArray[0], "loks") !== false) {
            $data = file_get_contents("./data/loks");
        } elseif ($urlArray[0] == "blokStav") {
            if ($urlArray[1] != "") {
                $data = file_get_contents("./data/" . $urlArray[1]);
            }
        } elseif (strpos($urlArray[0], "bloky") !== false) {
            $data = file_get_contents("./data/bloky");
        } else {
            include_once "./default.php";
        }
    }
    
    if (isset($data)) {
        //echo "Data:";
        //echo "<br>";
        //echo "<br>";
        echo $data;
    } else {
        echo 'page is: "' . htmlspecialchars($_GET["page"]) . '"';
        echo "<br>";
        echo "<br>";
        echo "<br> \$POST:";
        var_dump($_POST);
    }
} else {
    include_once 'ServerInfo.php';
}
?>