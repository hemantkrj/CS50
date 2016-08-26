<?php
 
    // configuration
    require("../includes/config.php"); 
 
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php", ["title" => "Sell"]);
    }
 
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $rows = CS50::query("SELECT * FROM portfolios WHERE pid = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
 
        if (count($rows) == 0)
        {
            apologize("don't have any shares of {$_POST["symbol"]}");
        }
 
        $row = $rows[0];
 
        if ($row["shares"] < $_POST["shares"])
        {
            apologize("enter lesser no. of shares.You have {$row["shares"]}.");
        }
 
        if ($row["shares"] == $_POST["shares"]) 
        {
            CS50::query("DELETE FROM portfolios WHERE pid = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        }
        else
        {
            CS50::query("UPDATE portfolios SET shares = ? WHERE pid = ? AND symbol = ?", $row["shares"] - $_POST["shares"], $_SESSION["id"], $_POST["symbol"]);
        }
 
        $stock = lookup($_POST["symbol"]);
 
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["shares"]*$stock["price"], $_SESSION["id"]);
 
        CS50::query("INSERT INTO history (id, transaction, symbol, shares, price, timestamp) VALUES (?, ?, ?, ?, ?, ?)", $_SESSION["id"], "SELL",strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"], date('Y-m-d h:i:s'));
 
        redirect("/");
 
    }
 
?>