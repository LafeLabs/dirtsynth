    <?php
    
    $dnaurl = "https://raw.githubusercontent.com/LafeLabs/notebook/main/json/dna.txt";
    
    if(isset($_GET["dna"])){
        $dnaurl = $_GET["dna"];
    }
    
    
    $baseurl = explode("json/",$dnaurl)[0];
    $dnaraw = file_get_contents($dnaurl);
    $dna = json_decode($dnaraw);
    
    mkdir("json");
    mkdir("php");
    mkdir("pages");
    mkdir("icons");
    mkdir("images");
    

    copy("https://raw.githubusercontent.com/LafeLabs/notebook/main/php/replicator.txt","replicator.php");
    
    
    
    foreach($dna->html as $value){
        
        copy($baseurl.$value,$value);
    
    }
    
    foreach($dna->icons as $value){
        
        copy($baseurl."icons/".$value,"icons/".$value);
    
    }
    
    foreach($dna->json as $value){
        if($value != "pageset.txt"){
            copy($baseurl."json/".$value,"json/".$value);
        }
        else{
            if(!file_exists("json/".$value)){
                copy($baseurl."json/".$value,"json/".$value);
            }
        }
        
    }
    
    foreach($dna->php as $value){
     
        copy($baseurl."php/".$value,"php/".$value);
        copy($baseurl."php/".$value,explode(".",$value)[0].".php");
    
    }
    
    foreach($dna->pages as $value){
        
//        if($value == "home"){
            copy($baseurl."pages/".$value,"pages/".$value);
  //      }
    
        
    }
    
    
    ?>
    <a href = "index.html">CLICK TO GO TO PAGE</a>
    <style>
    body{
        font-family:Courier;
        background-color:#F8F0E3;
    }
    a{
        font-size:3em;
    }
    </style>
