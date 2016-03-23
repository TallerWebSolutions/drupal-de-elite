# Requre a specific version in this file:
# gem 'zurb-foundation', '=4.3.2'
require 'zurb-foundation'
# Require any additional compass plugins here.

# Set this to the root of your project when deployed:
http_path = "../"
css_dir = "css"
sass_dir = "scss"
images_dir = "images"
javascripts_dir = "js"
fonts_dir = "fonts"

# Development configs.
if environment == :development

  output_style      = :expanded
  line_comments     = true
  debug             = true

# Production configs.
else

  output_style      = :compressed
  line_comments     = false
  debug             = false

end

# If you prefer the indented syntax, you might want to regenerate this
# project again passing --syntax sass, or you can uncomment this:
preferred_syntax = :sass
# and then run:
# sass-convert -R --from scss --to sass sass scss && rm -rf sass && mv scss sass
