<?php
$td = new TokyoDystopiaCore();
var_dump($td);
if (!$td->open("/tmp/foo", TOKYO_DYSTOPIA_IDBOWRITER | TOKYO_DYSTOPIA_IDBOCREAT)) {
    var_dump($td->errmsg());
    return -1;
}
$td->put(1, "foobar");
$td->put(2, "moriyoshi");
/*
var_dump($td->rnum());
var_dump($td->fsiz());
var_dump($td->sync());
*/
var_dump($td->search("mori"));
/*
var_dump($td->get(2));
var_dump($td->out(1));
var_dump($td->get(1));
*/
$td->close();
?>
