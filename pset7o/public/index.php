<?php

    // configuration
    require("../includes/config.php"); 

    $rows = CS50::query("SELECT * FROM portfolios WHERE pid = ?", $_SESSION["id"]);

    $stocks = []; 
    //$Total = 0.0;
    foreach ($rows as $row) {
		$stock = lookup($row["symbol"]); 
		if ($stock !== false)
		{
        	$stocks[] = [
            	"name" => $stock["name"],
            	"price" => $stock["price"],
            	"shares" => $row["shares"],
            	"symbol" => $row["symbol"]
			]; 
           // $Total = $Total + $row["shares"] * $stock["price"];
		}
	}
	$cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];

    

   // $Total = $Total + $cash;

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "stocks" => $stocks, "cash" => $cash]);



?>
