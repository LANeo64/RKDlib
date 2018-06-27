<h3>Chyba: takovej soubor tam není.</h3>
<p>Najdi si jinej soubor z níže uvedených:</p>
<?php
$dir = __DIR__.'/data';
$files = scandir($dir);
//var_dump($files);
?><ul><?php
foreach($files as $file) {?>
    <li><a href="<?php echo '/edsa-RKD/data/'.$file ?>"><?php echo $file ?></a></li>
<?php } ?>
</ul>