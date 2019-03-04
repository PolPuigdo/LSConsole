<?php

function llistat($dir)
{
    $currDir = getcwd()  . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (is_dir($currDir)) {
            return scandir($currDir);
        } else {
            return "$dir is not a directory";
        }
    } else {
        return scandir(getcwd());
    }

}

function ruta()
{
    return getcwd();
}

function stats_sistema()
{
    $sysStats = Array();

    $diskTotal = disk_total_space(DIRECTORY_SEPARATOR);
    $diskFree = disk_free_space(DIRECTORY_SEPARATOR);

    $gbFree = number_format($diskFree / pow(10, 9), 2);

    $percFree = number_format($diskFree / $diskTotal * 100, 2);
    $storageFree = $gbFree . "Free GB on disk: " . $percFree . "%";

    $gbFull = number_format(($diskTotal - $diskFree) / pow(10, 9), 2);
    $percFull = number_format(($diskTotal - $diskFree) / $diskTotal * 100, 2);
    $storageFull = $gbFull . "Full GB on disk: " . $percFull . "%";

    array_push($sysStats, $storageFree, $storageFull);
    return $sysStats;
}