<?php
$td = new TokyoDystopiaQgram();
var_dump($td);
$td->open("/tmp/td_qgram", TOKYO_DYSTOPIA_QDBOWRITER | TOKYO_DYSTOPIA_QDBOCREAT);
$td->put(1, "test");
$td->put(2, "foobar");
var_dump($td->search("ba", TOKYO_DYSTOPIA_QDBSSUBSTR));
$td->close();
?>
