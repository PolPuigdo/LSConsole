<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>LSConsole - Terminal Emulator</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css"
          integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">
</head>
<body>
<form action="executa.php" method="post">
    <main class="container">
        <section>
            <h3>LSConsole Terminal Emulator</h3>
            <br>
        </section>

        <div class="row">
            <span class="command" class=""><?php echo getcwd()?></span>

            <input class="col-xs-10 col-xs-10 col-md-8" type="text" name="input_cmd">
        </div>
    </main>
</form>

<main class="container-fluid">
    <section>
        <div class="row">
            <div class="col-md-12">
                <?php
                session_start();
                $output = Array();

                if (!empty($_SESSION['output'])) {
                    $output = $_SESSION['output'];
                    if (is_array($_SESSION['output'])) {
                        foreach ($output as $singleItem) {
                            echo $singleItem . "<br>";
                        }
                    } else {
                        echo $output . "<br>";
                    }

                    session_destroy();
                }
                ?>
            </div>
        </div>
    </section>
</main>

</body>
</html>