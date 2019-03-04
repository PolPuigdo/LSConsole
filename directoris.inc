<?php

include_once 'sistema.inc';

function crea_directori($dir)
{
    $currentDir = getcwd() . DIRECTORY_SEPARATOR . $dir;

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
    $currentDir = getcwd() . DIRECTORY_SEPARATOR . $dir;

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

function mou_directori($dir, $rutadesti)
{
    $currentDir = getcwd() . DIRECTORY_SEPARATOR . $dir;
    $destiny = getcwd() . DIRECTORY_SEPARATOR . $rutadesti;

    if ($dir != null && $rutadesti != null) {
        if (file_exists($currentDir)) {
            if (rename($currentDir, $destiny . DIRECTORY_SEPARATOR . $dir)) {
                return "$dir folder moved to $rutadesti successfully";
            } else {
                return "Something went wrong";
            }
        } else {
            return "$dir does not exists";
        }
    } else {
        return "Plase, enter the name of the folder and the rute";
    }
}

function copia_directori($dir, $rutadesti)
{
    $currentDir = getcwd() . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null && $rutadesti != null) {
        if (is_dir($currentDir)) {
            $files = scandir($currentDir);
            $filesToCopy = Array();

            foreach ($files as $item) {
                if ($item != "." && $item != "..") {
                    array_push($filesToCopy, copia_fitxer($dir.DIRECTORY_SEPARATOR.$item, $rutadesti));
                }
            }

            return $filesToCopy;
        } else {
            return "$dir is not a dir";
        }
    } else {
        return "Please, insert the name of the dir and the rute";
    }
}