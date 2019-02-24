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

function esborra_directori($dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (file_exists($currentDir)) {
            $files = scandir($currentDir);
            if (empty($files)) {
                if (is_dir($currentDir)) {
                    rmdir($currentDir);
                }
            } else {
                foreach ($files as $current) {
                    $actualFile = $currentDir . DIRECTORY_SEPARATOR . $current;

                    if ($actualFile != "." && $actualFile != "..") {
                        if (is_dir($actualFile)) {
                            esborra_directori($actualFile);
                        } else {
                            unlink($actualFile);
                        }
                    }
                }

                if (rmdir($currentDir)) {
                    return "Folder deleted successfully";
                }
            }
        } else {
            return "$dir does not exists";
        }
    } else {
        return "Plase, insert the name of the folder";
    }
}