<?php
 
    // configuration
    require("../includes/config.php"); 
 
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("pass_form.php", ["title" => "Change Password"]);
    }
 
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
      
      if($_POST["pass"]!=$_POST["repass"])
      {
          apologize("Passwords don't match");
      }
        CS50::query("UPDATE users SET hash=? WHERE id = ?", password_hash($_POST["pass"], PASSWORD_DEFAULT), $_SESSION["id"]);
        
        redirect("/");
    }
 
?>