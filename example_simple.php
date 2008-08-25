<?php
$td = new TokyoDystopiaSimple();
var_dump($td);
$td->open("/tmp/td_simple", TOKYO_DYSTOPIA_JDBOWRITER | TOKYO_DYSTOPIA_JDBOCREAT);
$td->put(1, array("test", "bar"));
var_dump($td->get(1));
var_dump($td->search("bar"));
$td->close();
?>
