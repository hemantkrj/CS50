<?php
 
    // configuration
    require("../includes/config.php"); 
 
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }
 
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
 
        if ($stock === false)
        {
            apologize("The stock not found");
        }
        
        
        //checks for non-negative, integer #
        if (preg_match("/^\d+$/",$_POST["shares"]) == false) 
        { 
            apologize("enter valid number");
        }
        
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];
 
        if ($cash < $_POST["shares"] * $stock["price"])
        {
            apologize("Insufficient Balance");
        }
 
        CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $_POST["shares"]*$stock["price"], $_SESSION["id"]);
 
        
        CS50::query("INSERT INTO portfolios (pid, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
        
        CS50::query("INSERT INTO history (id, transaction, symbol, shares, price, timestamp) VALUES (?, ?, ?, ?, ?, ?)", $_SESSION["id"], "BUY",strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"], date('Y-m-d h:i:s'));
        
        redirect("/");
    }
 
?>