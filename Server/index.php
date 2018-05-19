<?php
function resolveURI($url){
    
}

if (isset($_GET["page"])) {
    $url = $_GET["page"];
    if($url != ""){
        $urlArray = explode('/', $url);
        if($urlArray[0] == "lokStav"){
            if($urlArray[1] != "" ){
                $file = file_get_contents("./data/".$urlArray[1]);
            }
        } elseif( substr_compare ($urlArray[0], "loks", 0) >= 0 ) {
            $file = file_get_contents("./data/".$urlArray[0]);
        } elseif( $urlArray[0] == "blokStav" ) {
            if($urlArray[1] != "" ){
                $file = file_get_contents("./data/".$urlArray[1]);
            }
        } elseif( substr_compare ($urlArray[0], "bloky", 0) >= 0 ) {
            $file = file_get_contents("./data/".$urlArray[0]);
        }
    }    
    echo 'page is: "' . htmlspecialchars($_GET["page"]) . '"';
    echo "\r\n";
    //echo "\r\n \$POST:";
    //var_dump($_POST);
    echo "Data:";
    echo "\r\n";
    echo $file;
} else {
    include_once 'ServerInfo.php';
}
?>