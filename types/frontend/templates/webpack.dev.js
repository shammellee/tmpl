const fs   = require('fs');
const path = require('path');

const HtmlWebpackPlugin = require('html-webpack-plugin');
// const MiniCssExtractPlugin = require('mini-css-extract-plugin');

module.exports = {
  mode: 'development'
  ,entry: './src/main.ts'

  ,output:
  {
    path: path.resolve(__dirname, 'dist')
    ,filename: 'js/main.js'
  }

  ,resolve:
  {
    extensions:
    [
      '.ts'
      ,'.tsx'
      ,'.js'
    ]
  }

  ,module:
  {
    rules:
    [
      {
        test: /\.tsx?$/
        ,use: 'ts-loader'
        ,include: [path.resolve(__dirname, 'src')]
      }

      ,{
        test: /\.styl$/
        ,use:
        [
          {
            loader: 'style-loader'
          }
          // ,{
            // loader: MiniCssExtractPlugin.loader
            // ,options:
            // {
              // publicPath: '/dist/css'
            // }
          // }
          ,{
          // {
            loader: 'css-loader'   // translate CSS to CommonJS
          }
          ,{
            loader: 'stylus-loader'  // translate Stylus to CSS
            ,options:
            {
              stylusOptions:
              {
                use: ['nib']
                ,import: ['nib']
                ,compress: true
                ,includeCSS: true
              }
            }
          }
        ]
      }
    ]
  }

  ,plugins:
  [
    new HtmlWebpackPlugin(
    {
      // filename: 'index.html'
      template: 'src/index.html'
      ,hash: true
      // ,publicPath: 'dist'
    })
    /*
    new MiniCssExtractPlugin(
    {
      filename: '[name].css'
      ,chunkFilename: '[id].css'
    })
    */
    // new BundleAnalyzerPlugin()
  ]

  ,devServer:
  {
    contentBase: path.join(__dirname, 'dist')
    ,port: 8000
    // ,writeToDisk: true
  }
};

