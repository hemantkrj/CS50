<?php
 
    // configuration
    require("../includes/config.php"); 
 
    $positions = CS50::query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
 
    render("history_show.php", ["positions" => $positions, "title" => "History"]);
 
?>