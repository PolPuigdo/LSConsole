<?php

function find_fitxer($fitxer, $dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;
    $files = scandir($currentDir);

    if ($fitxer != null) {
        foreach ($files as $fileToFind) {
            if (is_file($currentDir . DIRECTORY_SEPARATOR . $fileToFind)) {
                if (strtolower($fitxer) == strtolower($fileToFind)) {
                    return "The file: $fitxer find in: $currentDir";
                }
            }
        }

        return "$fitxer cannot be find";
    } else {
        return "Plase, insert the file and the dir";
    }
}