<?php

include_once 'sistema.inc';

function crea_directori($dir)
{
    $currDir = getcwd() . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (!file_exists($currDir)) {
            if (mkdir($currDir)) {
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
    $currDir = getcwd() . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (file_exists($currDir)) {
            $files = scandir($currDir);
            if (empty($files)) {
                if (is_dir($currDir)) {
                    rmdir($currDir);
                }
            } else {
                foreach ($files as $file) {
                    $actualFile = $currDir . DIRECTORY_SEPARATOR . $file;

                    if ($actualFile != "." && $actualFile != "..") {
                        if (is_dir($actualFile)) {
                            esborra_directori($actualFile);
                        } else {
                            unlink($actualFile);
                        }
                    }
                }

                if (rmdir($currDir)) {
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
    $currDir = getcwd() . DIRECTORY_SEPARATOR . $dir;
    $destiny = getcwd() . DIRECTORY_SEPARATOR . $rutadesti;

    if ($dir != null && $rutadesti != null) {
        if (file_exists($currDir)) {
            if (rename($currDir, $destiny . DIRECTORY_SEPARATOR . $dir)) {
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
    $currDir = getcwd() . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null && $rutadesti != null) {
        if (is_dir($currDir)) {
            $files = scandir($currDir);
            $filesInDir = Array();

            foreach ($files as $file) {
                if ($file != "." && $file != "..") {
                    array_push($filesInDir, copia_fitxer($dir.DIRECTORY_SEPARATOR.$file, $rutadesti));
                }
            }

            return $filesInDir;
        } else {
            return "$dir is not a dir";
        }
    } else {
        return "Please, insert the name of the dir and the rute";
    }
}