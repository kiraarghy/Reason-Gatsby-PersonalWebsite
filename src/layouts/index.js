import React from 'react'
import PropTypes from 'prop-types'
import Helmet from 'react-helmet'

import './index.css'

const Layout = ({ children }) => (
  <div>
    <div
      style={{
        margin: '0 auto',
        maxWidth: '100%',
        height: '100%',
      }}
    >
      <Helmet>
        <title>Personal Portfolio page of Kara Stubbs</title>
      </Helmet>
      {children()}
    </div>
  </div>
)

Layout.propTypes = {
  children: PropTypes.func,
}

export default Layout
