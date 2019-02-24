<?php

include_once 'sistema.inc';

function crea_directori($dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (!file_exists($currentDir)) {
            if (mkdir($currentDir)) {
                return "$dir folder created successfully";
            } else {
                return "Something went wrong creating the folder";
            }
        } else {
            return "$dir folder already exists";
        }
    } else {
        return "Please, insert a name for the folder";
    }
}