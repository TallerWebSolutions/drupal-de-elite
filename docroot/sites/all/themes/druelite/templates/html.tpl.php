<!doctype html>
<html lang="<?php print $language->language ?>" class="no-js">
  <head profile="<?php print $grddl_profile ?>">
    <meta http-equiv="X-UA-Compatible" content="IE=edge, chrome=1">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <?php print $head ?>
    <title><?php print $head_title ?></title>
    <link rel="stylesheet" type="text/css" href="//fonts.googleapis.com/css?family=Open+Sans" />
    <?php print $styles ?>
    <script src="https://apis.google.com/js/platform.js"></script>
    <?php print $scripts ?>
    <div id="fb-root"></div>
  </head>
  <body class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php print $page_top ?>
    <?php print $page ?>
    <?php print $page_bottom ?>
  </body>
</html>
