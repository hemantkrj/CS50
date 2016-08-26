<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    $query = $_GET["geo"];
 
    // tokenize by all non-alpha numeric characters
    $token = preg_split("/[^a-zA-Z\d]/", $query, -1, PREG_SPLIT_NO_EMPTY);    
 
 
    // See if the last elment is a zip
    $last = array_pop($token);
    $zip = -1;
 
    if (is_numeric($last)){
        $zip = intval($last);
    }
    else
    {
        array_push($token, $last);
    }
 
    $keyword= implode(" ", $token);
 
    //search places table
 
    // resultset where place matches,zip doesn't. 
    $zipunmatch = CS50::query("SELECT * FROM places WHERE MATCH (place_name, admin_name1, admin_code1,admin_name2, admin_code2) AGAINST (? IN NATURAL LANGUAGE MODE) AND postal_code != $zip", $keyword);
    
    // resultset where zip code matches, but place does not. 
    $zipmatch = CS50::query("SELECT * FROM places WHERE NOT MATCH (place_name, admin_name1, admin_code1,admin_name2, admin_code2) AGAINST (? IN NATURAL LANGUAGE MODE) AND postal_code = $zip", $keyword);
 
    // where both match
    $bothmatch = CS50::query("SELECT * FROM places WHERE MATCH (place_name, admin_name1, admin_code1,admin_name2, admin_code2) AGAINST (? IN NATURAL LANGUAGE MODE) AND postal_code = $zip", $keyword);
 
    // merge the three parts into one aray
    $places = array_merge($zipunmatch, $zipmatch, $bothmatch);
 

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>